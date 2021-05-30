#include<iostream>
#include<string>
#include<vector>

int main()
{
	int _input = 0;
	string pattern,text;
	AlgoKeeper runner;
	string enteredString;
	std::vector<string> texts;

	bool loop =true;

	while(loop)
	{
		cout<<"\n\n *************************** PATTERN MATCHING *******************************";
		std::cout<<"\nPlease Enter\n 1 for Naive \n 2 for Rabin Karp \n 3 for KMP \n 4 for a Trie \n Enter other number to exit";
		std::cin>>_input;
		std::cout<<"You entered "<<_input<<endl;

	    switch(_input)
	    {
	    	case 1: //Naive
	    		std::cout<<"Please enter a text ";
	    		cin>>text;
	    		std::cout<<"Please enter a pattern";
	    		cin>>pattern;
	    		cout<<runner.NaivePatternSearch(text,pattern);
	    		break;
	    	case 2:	//Rabin Karp
	    		std::cout<<"Please enter a text ";
	    		cin>>text;
	    		std::cout<<"Please enter a pattern";
	    		cin>>pattern;
	    		cout<<runner.RabinKarpPatternSearch(text,pattern);
	    		break;
	    	case 3: //KMP
	    		std::cout<<"Please enter a text ";
	    		cin>>text;
	    		std::cout<<"Please enter a pattern";
	    		cin>>pattern;

	    		cout<<runner.KMPPatternSearch(text,pattern);
	    		break;
	    	case 4: //Trie

	    		do{
	    			cout<<endl<<"Type a string to insert in Trie \n Or Type \"_exit\" to enter Pattern\n";
	    			cin>>enteredString;
	    			if(enteredString!="_exit")
	    				texts.emplace_back(enteredString);
	    		}while(enteredString != "_exit");
	    		cout<<"\nEnter the pattern here : ";
	    		cin>>pattern;

				for(string s:texts)
					cout<<"\n "<<s;
	    		cout<<(runner.TriePatternSearch(texts,pattern) ? "found" : "not found");
				break;
	    	default:
				loop = false;
	    		break;
	    }

	}
	return 0;
}
