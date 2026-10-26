using namespace std;
#include <iostream>
#include <vector>

class Parrot {
private:
	vector<string> words;
public:
	
	Parrot(string Word) {
		words.push_back(Word);
	}
	
	void say(int quantity) {
	    for (int i=0;i<quantity;i++)
	    {
	        int n = rand() % words.size();
		    cout<<words[n]<<"\n";
	    }
	}
	
	void learn(string newWord)
	{
	    words.push_back(newWord);
	}
	
	void changeWord(string newWord) {
		words[0] = newWord;
	}
	
};

int main() {

	Parrot parrot("bazinga");
	
	parrot.say(1);
	
	parrot.changeWord("Jarona");
	
	parrot.say(1);
	
	parrot.learn("blue");
	parrot.learn("yellow");
	parrot.learn("pink");
	parrot.learn("orange");
	parrot.learn("green");
	parrot.learn("gold");
	parrot.learn("black");
	
	parrot.say(10);

	return 0;

}