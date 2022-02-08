// There can be 10^6 unique ingredients
vector<bool> taken(1000000);
vector<string> ingredients;
map<string, pair<vector<int>, vector<int>>> ing;

// There is 3 parameters. And there are no overlapping subproblem
/*int dp[100000];
int DnC(int n, int type, vector<bool> removed)
{
    if (n < 0)
    {
        return 0;
    }
    int count = 0;
    if (type == 0)
    {
        vector<int> likes = ing[ingredients[n]].first;
        for (int i : likes)
        {
            if (!removed[i])
            {
                removed[i] = true;
                count++;
            }
        }
    }
    if (type == 1)
    {
        vector<int> dislikes = ing[ingredients[n]].second;
        for (int i : dislikes)
        {
            if (!removed[i])
            {
                removed[i] = true;
                count++;
            }
        }
    }
    int a = DnC(n - 1, 1, removed);
    int b = DnC(n - 1, 0, removed);
    if (a < b)
    {
        count += a;
    }
    else
    {
        count += b;
    }
    // cout << count << endl;
    return count;
}
vector<string> solve(vector<vector<string>> likes, vector<vector<string>> dislikes)
{
    // We will use dp. We will take the maximum customers by picking or without picking an ingredient.
    // If we don't put an incredients we will remove the clients that likes that ingredient.
    // If we put an incredients we will remove the clients that dislikes that ingredient
    // Need an dp for all the unique element. Store O if we don't put that ingredient, store 1 if we put that ingredient.
    // Need an additional array to store the clients that likes or dislikes that ingredient
    int n = likes.size();
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (string s : likes[i])
        {
            ing[s].first.push_back(i);
        }
        for (string s : dislikes[i])
        {
            ing[s].second.push_back(i);
        }
    }
    for (auto i : ing)
    {
        ingredients.push_back(i.first);
    }
    cout << DnC(ingredients.size(), -1, vector<bool>(n)) << endl;
    return vector<string>();
}*/
