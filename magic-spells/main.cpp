#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
    auto max_common_seq_len = [](const std::string& a, const std::string& b) {
        int a_l = a.length();
        int b_l = b.length();
        vector<int> tab(a_l * b_l);
        for(int i = 0; i < a_l; ++i)
        {
            for(int j = 0; j < b_l; ++j)
            {
                if(a[i] == b[j])
                {
                    int base = (i > 0 && j > 0) ? tab[(i - 1) * b_l + j - 1] : 0; 
                    tab[i*b_l + j] = base + 1;
                } else {
                    int upper = (i > 0) ? tab[(i - 1)*b_l +j] : 0;
                    int left = (j > 0) ? tab[i*b_l + j - 1] : 0;
                    tab[i*b_l + j] = std::max(upper, left);
                }
            }
        }
        return tab.back();
    };

    if(auto* s = dynamic_cast<Fireball*>(spell)) {
        s->revealFirepower();
    } else if (auto* s = dynamic_cast<Thunderstorm*>(spell)) {
        s->revealThunderpower();
    } else if (auto* s = dynamic_cast<Waterbolt*>(spell)) {
        s->revealWaterpower();
    } else if (auto* s = dynamic_cast<Frostbite*>(spell)) {
        s->revealFrostpower();
    } else {
        auto name = spell->revealScrollName();
        std::cout << max_common_seq_len(name, SpellJournal::journal) << "\n";
    }
  /* end of code */ 
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}