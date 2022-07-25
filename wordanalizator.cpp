#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main()
{
  label:
    string FileWay;
    string UserInput="y";
    
    map <string, int> Dictionary {{"",0}};
    
    cout <<"type way to file or use TestFile?" \
      <<endl;
    cin >>UserInput;
    if(UserInput=="y")
      FileWay="/storage/emulated/0/Download/cpp/TestFile.txt";
    else
    {
      cout<<"Enter the way to file to analaze:" \
        <<endl;
      cin>>FileWay;
    }
    
    fstream File(FileWay);
    
    if(File.is_open())
    {
      string Content;
      //File.read (File,Content);
      while (File.good())
      {
        getline(File,Content);
      }
      
    
      string Word;
    
      for (auto Start=Content.cbegin();Start!=Content.cend();++Start)
      {
        if(isalpha(*Start))
        {
          Word+=*Start;
        }
        else
        {
          auto MapFinder =Dictionary.find(Word);
          if(MapFinder !=Dictionary.cend())
            MapFinder->second+=1;
          else
          {
            Dictionary.insert(make_pair(Word,1));
            Word="";
          }
        }
      }
      }
      else cout<<"Impossibly to open!"<<endl;
    
    //outpuy for user
    for(auto MapFinder=Dictionary.cbegin(); MapFinder!=Dictionary.cend(); ++MapFinder)
    {
      cout<<MapFinder->first<<" - "<<MapFinder->second<<endl;
      
    }
    cout<<Dictionary.size()<<endl;
    
    File.close();
    
    string ElseTime="y";
    cout<<"else round?"<<endl;
    cin>>ElseTime;
    if(ElseTime=="y") goto label;
    
return 0;
}