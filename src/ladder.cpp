#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "ERROR: " << word1 << " and " << word2 << " " << msg << endl;
    return;
}

/* SOURCE: Code to calulate edit distance based on Optimal String Alignment Distance pseudocode from Wikipedia:
https://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance */
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {

    int lenOne = str1.length();
    int lenTwo = str2.length();

    // Calculate how much the words differ in length
    int lenDiff = abs((int)lenOne - lenTwo);
    // If lengths of words differ by more than one, return false
    if (lenDiff > 1) {
        return false;
    }

    vector<vector<int>> dist (lenOne + 1, vector<int>(lenTwo + 1));

    for (int i = 0; i <= lenOne; ++i) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= lenTwo; ++j) {
        dist[0][j] = j;
    }

    for (int k = 1; k <= lenOne; ++k) {
        for (int l = 1; l <= lenTwo; ++l) {
            int cost = 0;

            if (!(str1[k - 1] == str2[l - 1])) {
                cost = 1;
            }

            dist[k][l] = min(dist[k - 1][l] + 1, min(dist[k][l - 1] + 1, dist[k - 1][l - 1] + cost));

        }
    }

    return dist[lenOne][lenTwo] <= d;

}

bool is_adjacent(const string& word1, const string& word2) {

    return edit_distance_within(word1, word2, 1);

}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {

    if (word_list.find(end_word) == word_list.end()) {
        cout << end_word << " is not in the dictionary" << endl;
        return {};
    }

    if (begin_word == end_word) {
        error(begin_word, end_word, "are the same word");
        return {};
    }

    queue<vector<string>> queue;
    set<string> visited;

    vector<string> begin{begin_word};

    queue.push(begin);
    visited.insert(begin_word);

    while (!queue.empty()) {
        auto ladder = queue.front();
        queue.pop();
        auto last_word = ladder[ladder.size() - 1];

        for (auto word : word_list) {
            if (is_adjacent(last_word, word)) {
                // If word is not in visited set...
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    auto newLadder = ladder;
                    newLadder.push_back(word);
                    if (word == end_word) {
                        return newLadder;
                    }
                    queue.push(newLadder);
                }
            }
        }

    }

    return {};

}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        throw runtime_error("Can't open input file");
    }
    for (string s; in >> s;) {
        word_list.insert(s);
    }
    in.close();

}

void print_word_ladder(const vector<string>& ladder) {
    for (auto s : ladder) {
        cout << s << " ";
    }
}

void verify_word_ladder() {
    
}