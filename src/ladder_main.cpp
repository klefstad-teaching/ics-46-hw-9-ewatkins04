#include "ladder.h"

int main() {

    set<string> words;

    load_words(words,"src/words.txt");

    auto result = generate_word_ladder("marty", "curls", words);

    cout << result.size() << endl;

    print_word_ladder(result);

    return 0;
}