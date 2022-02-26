#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Job sequencing
// We will complete all the projects. No loss.
// But we may not always work on a project.
// We will first finish the projects that meets all the requirements.
// Than we will increase skill level and finish the rest ones.
// Only skill is common between contributor and project.
// Why not keep an array of skills?

// How will we know if we can work on a project?
class Skill
{
public:
    string sName; // Name of skill
    int level;    // Level of skill
    Skill(string sName, int level)
    {
        this->sName = sName;
        this->level = level;
    }
};
class Project
{
public:
    string pName;
    int nDays, score, bestDay;
    int nRoles; // <100
    vector<Skill> skills;
    Project(string pName, int nDays, int score, int bestDay, int nRoles)
    {
        this->pName = pName;
        this->nDays = nDays;
        this->score = score;
        this->bestDay = bestDay;
        this->nRoles = nRoles;
    }
    void addSkill(string sName, int level)
    {
        skills.push_back(Skill(sName, level));
    }
    bool operator<(const Project &p)
    {
        if (this->bestDay < p.bestDay)
        {
            return true;
        }
        else if (this->bestDay == p.bestDay)
        {
            if (this->nDays > p.nDays)
            {
                return true;
            }
            else if (this->nDays == p.nDays)
            {
                return this->score > p.score;
            }
            return false;
        }
        return false;
    }
};
class Compare
{
public:
    bool operator()(Project p1, Project p2)
    {
        if (p1.bestDay > p2.bestDay)
        {
            return true;
        }
        else if (p1.bestDay == p2.bestDay)
        {
            if (p1.nDays < p2.nDays)
            {
                return true;
            }
            else if (p1.nDays == p2.nDays)
            {
                return p1.score < p2.score;
            }
            return false;
        }
        return false;
    }
};
class Contributor
{
public:
    string cName; // Contributor Name
    int nSkills;  // # Contributor's skills <100
    map<string, int> skills;
    Contributor()
    {
        nSkills = 0;
    }
    Contributor(string cName, int nSkills)
    {
        this->cName = cName;
        this->nSkills = nSkills;
    }
    Contributor(const Contributor &c)
    {
        this->cName = c.cName;
        this->nSkills = c.nSkills;
        this->skills = c.skills;
    }
    void addSkill(string sName, int level)
    {
        skills[sName] = level;
    }
    int getSkillLevel(string sName)
    {
        if (skills.find(sName) == skills.end())
        {
            return 0;
        }
        return skills[sName];
    }
    void improveSkill(string sName)
    {
        if (skills.find(sName) == skills.end())
        {
            skills[sName] = 0;
        }
        skills[sName]++;
    }
};
vector<Contributor> contributors;
map<string, map<string, Contributor>> skillMap; // map<sName,map<cName,level>>
vector<Project> projects;
void setContributors(int nContributors)
{
    // Contributors
    for (int i = 0; i < nContributors; i++)
    {
        string cName; // Contributor Name
        int nSkills;  // # Contributor's skills <100
        cin >> cName >> nSkills;
        contributors.push_back(Contributor(cName, nSkills));
        for (int j = 0; j < nSkills; j++)
        {
            string sName; // Name of skill
            int level;    // Level of skill
            cin >> sName >> level;
            contributors.back().addSkill(sName, level);
            skillMap[sName][cName] = contributors.back();
        }
    }
}
void setProjects(int nProjects)
{
    // Projects
    for (int i = 0; i < nProjects; i++)
    {
        string pName; // Project Name
        int nDays, score, bestDay;
        int nRoles; // <100
        cin >> pName >> nDays >> score >> bestDay >> nRoles;
        projects.push_back(Project(pName, nDays, score, bestDay, nRoles));
        for (int i = 0; i < nRoles; i++)
        {
            string sName;
            int level;
            cin >> sName >> level;
            projects.back().addSkill(sName, level);
        }
    }
}
vector<Contributor> cList;
bool found;
int count;

class CompareDegree
{
public:
    bool operator()(pair<vector<Contributor>, int> p1, pair<vector<Contributor>, int> p2)
    {
        return p1.first.size() > p2.first.size();
    }
};
void getContributorList(Project p)
{
    // Count the number of compatibles for each role
    vector<vector<Contributor>> degree(p.nRoles);
    std::priority_queue<pair<vector<Contributor>, int>, std::vector<pair<vector<Contributor>, int>>, CompareDegree> pq;
    for (int i = 0; i < p.nRoles; i++)
    {
        string skill = p.skills[i].sName;
        int req = p.skills[i].level;
        for (auto j : skillMap[skill])
        {
            if (j.second.skills[skill] >= req)
            {
                degree[i].push_back(j.second);
            }
        }
        if (degree[i].size())
        {
            pq.push({degree[i], i});
        }
    }
    int count = 0;
    vector<bool> booked(p.nRoles);
    map<string, bool> taken;
    map<string, int> skillLevel; // After selecting contributors we will map there skill levels. So that we can use them as mentors later
    vector<Contributor> cList(p.nRoles);
    while (!pq.empty())
    {
        pair<vector<Contributor>, int> d = pq.top();
        pq.pop();
        string skill = p.skills[d.second].sName;
        for (auto c : d.first)
        {
            cout << c.cName << endl;
            if (!taken[c.cName])
            {
                booked[d.second] = true;
                taken[c.cName] = true;
                cList[d.second] = c;
                skillLevel[skill] = max(skillLevel[skill], c.skills[skill]);
                count++;
                break;
            }
        }
    }
    // Now the rest of the roles
    while (count < p.nRoles)
    {
        bool flag = false;
        for (int i = 0; i < p.nRoles; i++)
        {
            string skill = p.skills[i].sName;
            int req = p.skills[i].level;
            if (!booked[i])
            {
                if (skillLevel[skill] >= req)
                {
                    for (auto c : contributors)
                    {
                        if (!taken[c.cName] && c.skills[skill] + 1 >= req)
                        {
                            booked[i] = true;
                            taken[c.cName] = true;
                            cList[i] = c;
                            skillLevel[skill] = max(skillLevel[skill], c.skills[skill]);
                            count++;
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (count == p.nRoles)
    {
        ::cList = cList;
        found = true;
    }
}
vector<pair<string, vector<Contributor>>> solve()
{
    std::priority_queue<Project, std::vector<Project>, Compare> pq(projects.begin(), projects.end());
    vector<pair<string, vector<Contributor>>> result;
    while (!pq.empty())
    {
        Project p = pq.top();
        found = false;
        int m = pq.size();
        pq.pop();
        for (int i = 0; i < m; i++)
        {
            cout << i << endl;
            cout << p.pName << endl;
            ::count = 0;
            getContributorList(p);
            if (found)
            {
                break;
            }
            else
            {
                if (pq.empty())
                {
                    break;
                }
                Project tmp = p;
                p = pq.top();
                pq.pop();
                pq.push(tmp);
            }
        }
        if (!found)
        {
            break;
        }
        cout << "FOUND " << p.pName << endl;
        for (int i = 0; i < p.nRoles; i++)
        {
            string skill = p.skills[i].sName;
            if (cList[i].skills[p.skills[i].sName] <= p.skills[i].level)
            {
                skillMap[skill][cList[i].cName].skills[skill]++;
            }
        }
        result.push_back({p.pName, cList});
        cout << "DONE" << endl;
    }
    return result;
}
int main()
{
    freopen("in2.txt", "r", stdin);
    int nContributors, nProjects; // <10^5
    cin >> nContributors >> nProjects;
    setContributors(nContributors);
    setProjects(nProjects);
    vector<pair<string, vector<Contributor>>> result = solve();
    freopen("out2.txt", "w", stdout);
    cout << result.size() << endl;
    for (auto i : result)
    {
        cout << i.first << endl;
        for (auto j : i.second)
        {
            cout << j.cName << " ";
        }
        cout << endl;
    }
}