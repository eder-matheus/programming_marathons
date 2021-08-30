// digitando - uri 1284

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

const int ALPHABET = 27;

struct vertex {
  std::vector<int> edges;
  bool key = false;
  int children_cnt;

  vertex() {
    edges.resize(ALPHABET);
    std::fill(std::begin(edges), std::end(edges), -1);
    children_cnt = 0;
  }
};

void addToTrie(std::vector<vertex>& trie, const std::string& s) {
  int v = 0;
  for (const char ch : s) {
    int c = ch - 'a';
    if (trie[v].edges[c] == -1) {
      trie[v].edges[c] = trie.size();
      trie[v].children_cnt++;
      trie.emplace_back();
    }
    v = trie[v].edges[c];
  }
  trie[v].key = true;
}

int findWord(const std::vector<vertex>& trie, const std::string& s) {
  int cnt = 0;
  int v = 0;
  for (const char ch : s) {
    int c = ch - 'a';
    v = trie[v].edges[c];
    if (trie[v].children_cnt > 1 || trie[v].key) {
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int word_count;
  while (std::cin >> word_count) {
    std::vector<vertex> trie(1);
    int press_keys = 0;

    std::vector<std::string> words(word_count);
    for (int i = 0; i < word_count; i++) {
      std::cin >> words[i];
      addToTrie(trie, words[i]);
    }
    for (int i = 0; i < word_count; i++) {
      press_keys += findWord(trie, words[i]);
    }
    std::cout << std::fixed << std::setprecision(2) << (float)press_keys/word_count << "\n";
  }

  return 0;
}
