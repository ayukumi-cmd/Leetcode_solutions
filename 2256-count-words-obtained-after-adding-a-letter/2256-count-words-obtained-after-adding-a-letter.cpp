class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        unordered_set<string> startSet;
        
		
        for(auto word : startWords) {
			
            sort(word.begin(), word.end()); 
            startSet.insert(word);
        }
        

        int count = 0;
        
        for(auto word : targetWords) {
			
            sort(word.begin(), word.end());
            
            for(int i=0; i<word.size(); i++) {
			
                string sortedWord = word.substr(0, i) + word.substr(i+1);

                if(startSet.find(sortedWord) != startSet.end()) {
		
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};