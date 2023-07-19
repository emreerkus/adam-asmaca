#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool createGameEnv()
{
    int life = 5;
    vector<char> used_things;
    cout << "Type whatever you want which is valid on dictionary: ";
    string input;
    cin >> input;

    string status;
    status.assign(input.length(), '-');

    while (life > 0){
        cout << "You used before these: [ ";
        for(char c : used_things){
            cout << c << " ";
        }
        cout << "]" << endl;
        cout << "Type a letter you think that actual word contains it: ";
        char letter;
        cin >> letter;
        bool is_present = false;
        for(char c : used_things){
            if(c == letter){
                is_present = true;
            }
        }
        if(!is_present){
            used_things.push_back(letter);
            int count = 0;
            for (int i=0; i<input.length(); i++){
                if(letter == input[i]){
                    count += 1;
                    status[i] = letter;
                    cout << "Congrats, you got it!" << endl;
                    if(status == input){
                        return true;
                    }
                }
            }
            if(count == 0 && life != 1){
                life -= 1;
                cout << "Oh no, try again... but do not forget that you " << life << " life/lives left" << endl;
            }
        }
        else{cout << "You have already chosen this letter... " << endl;};
        cout << "Status: " << status << endl;
    }
    return false;
}

int main()
{
    bool result = createGameEnv();
    if(result){
        cout << "You won!" << endl;
    }
    else{
        cout << "Try again sometimes... because you lost..." << endl;
    }
    return 0;
}
