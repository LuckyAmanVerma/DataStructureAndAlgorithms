/*
Time Complexity: O(N^2)
Space Complexity: O(N^2) for adjacency list
*/

// Step 1: Adjacency list banao
void buildAdjList(vector<vector<int>>& mat, vector<vector<int>>& adj) {
    int n = mat.size();
    adj.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 1)
                adj[i].push_back(j);
}

// Step 2: Celebrity candidate find karo jiska adj empty ho
int findCelebrityCandidate(vector<vector<int>>& adj) {
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        if (adj[i].empty())
            return i;
    }
    return -1;
}

// Step 3: Check karo sab usko jaante hain
bool isCelebrity(int candidate, const vector<vector<int>>& adj) {
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        // Check if candidate is in adj[i]'s neighbor list
        if(find(adj[i].begin(), adj[i].end(), candidate) == adj[i].end())
            return false; // kisi ne candidate ko nahi jaana
    }
    return true;
}

int celebrityGraphMethod(vector<vector<int>>& mat) {
    vector<vector<int>> adj;
    buildAdjList(mat, adj);

    int candidate = findCelebrityCandidate(adj);
    if (candidate == -1) return -1;

    if (isCelebrity(candidate, adj))
        return candidate;

    return -1;
}
