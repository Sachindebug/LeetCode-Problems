class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
      deque<string> a,b;
      sentence1+=' ', sentence2+=' ';  
      string temp="";  
	  
      for(int i=0; i<sentence1.length(); i++)
      {
        if(sentence1[i]==' ') 
        {
          a.push_back(temp);
          temp="";  
        }
        else temp+=sentence1[i];  
      }
	  
      temp="";  
      for(int i=0; i<sentence2.length(); i++)
      {
        if(sentence2[i]==' ') 
        {
          b.push_back(temp);
          temp="";  
        }
        else temp+=sentence2[i];  
      }
	  
      while(a.size()&&b.size() && a.front()==b.front())  
            a.pop_front(), b.pop_front();
			
      while(a.size()&&b.size() && a.back()==b.back())  
            a.pop_back(), b.pop_back(); 
			
      if(a.size()==0 || b.size()==0) return true;
      return false;  
    }
};