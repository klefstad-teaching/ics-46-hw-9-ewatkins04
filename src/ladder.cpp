#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "ERROR: " << word1 << " and " << word2 << " " << msg << endl;
    return;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {

}

bool is_adjacent(const string& word1, const string& word2) {

    // Calculate how much the words differ in length
    int lenDiff = abs(int(word1.length() - word2.length()));

    // If lengths of words differ by more than one, return false
    if (lenDiff > 1) {
        return false;
    }
    
    if (lenDiff == 0) {

    }
    else {
        
    }


}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {

    if (begin_word == end_word) {
        error(begin_word, end_word, "are the same word");
    }
    queue<string> queue;
    set<string> visited;

    queue.push(begin_word);
    visited.insert(begin_word);

    while (!queue.empty()) {
        string ladder = queue.front();

        for (auto word : word_list) {
            if (is_adjacent(last_word, word)) {
                // If word is not in visited set...
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    auto newLadder = ladder;
                    newLadder
                }
            }
        }

    }




}

void load_words(set<string> & word_list, const string& file_name) {

}

void print_word_ladder(const vector<string>& ladder) {

}

void verify_word_ladder() {

}