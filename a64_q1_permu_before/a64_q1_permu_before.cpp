#include <bits/stdc++.h>
using namespace std;

int totalElements, totalConstraints;
vector<int> beforeElement;
vector<int> permutation;
vector<bool> usedElements;

void generatePermutations(int step) {
  if (step == totalElements) {
    for (auto &element : permutation) {
      cout << element << ' ';
    }
    cout << "\n";
  } else {
    for (int i = 0; i < totalElements; i++) {
      if (usedElements[i] == false && (beforeElement[i] == -1 || usedElements[beforeElement[i]])) {
        permutation[step] = i;
        usedElements[i] = true;
        generatePermutations(step + 1);
        usedElements[i] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> totalElements >> totalConstraints;
  beforeElement = vector<int>(totalElements, -1);
  usedElements.resize(totalElements);
  permutation.resize(totalElements);

  for (int i = 0; i < totalConstraints; i++) {
    int previousElement, currentElement;
    cin >> previousElement >> currentElement;
    beforeElement[currentElement] = previousElement;
  }

  generatePermutations(0);
}

