#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Hero {
    int pos;
    int health;
    char team;
};

// Sort heroes based on position
void sortByPosition(vector<Hero>& heroes) {
    sort(heroes.begin(), heroes.end(), [](const Hero& a, const Hero& b) {
        return a.pos < b.pos;
    });
}

// Resolve all battles in the lane
vector<Hero> resolveBattles(const vector<Hero>& heroes) {
    vector<Hero> result;

    for (const Hero& h : heroes) {
        if (h.team == 'R') {
            result.push_back(h);
        } else {
            bool resolved = false;
            while (!result.empty() && result.back().team == 'R') {
                if (result.back().health < h.health) {
                    Hero copy = h;
                    --copy.health;
                    result.pop_back();
                    result.push_back(copy);
                    resolved = true;
                    break;
                } else if (result.back().health == h.health) {
                    result.pop_back();
                    resolved = true;
                    break;
                } else {
                    --result.back().health;
                    resolved = true;
                    break;
                }
            }
            if (!resolved) {
                result.push_back(h);
            }
        }
    }
    return result;
}

// Map original order to final health
vector<int> getFinalHealths(const vector<Hero>& original, const vector<Hero>& survived) {
    vector<int> finalHealths;
    for (const Hero& h : original) {
        bool found = false;
        for (const Hero& s : survived) {
            if (h.pos == s.pos && h.team == s.team) {
                finalHealths.push_back(s.health);
                found = true;
                break;
            }
        }
        if (!found) finalHealths.push_back(0);
    }
    return finalHealths;
}

// Input parsing function
vector<Hero> readHeroes(int n) {
    vector<Hero> heroes(n);
    cout << "Enter positions: ";
    for (int i = 0; i < n; ++i) cin >> heroes[i].pos;
    cout << "Enter health: ";
    for (int i = 0; i < n; ++i) cin >> heroes[i].health;
    cout << "Enter team string: ";
    for (int i = 0; i < n; ++i) cin >> heroes[i].team;
    return heroes;
}

// Output function
void printHealths(const vector<int>& healths) {
    cout << "Remaining Healths: ";
    for (int h : healths) cout << h << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of heroes: ";
    cin >> n;

    vector<Hero> heroes = readHeroes(n);

    vector<Hero> sortedHeroes = heroes;
    sortByPosition(sortedHeroes);

    vector<Hero> survived = resolveBattles(sortedHeroes);
    vector<int> finalHealths = getFinalHealths(heroes, survived);

    printHealths(finalHealths);

    return 0;
}
