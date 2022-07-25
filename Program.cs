using System;
using System.Linq;
using System.Net;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace Web
{
	public static class Program
	{
		public static void Main()
		{
		WebClient wc = new WebClient();
		Console.WriteLine("Enter link to txt file or just press \'Enter\': ");
		string webRef=Console.ReadLine();
		
		if(webRef.Length<5)
			webRef="https://filesamples.com/samples/document/txt/sample3.txt";
	
        Stream str = wc.OpenRead(webRef);
        //example https://filesamples.com/samples/document/txt/sample3.txt"
        StreamReader sr = new StreamReader(str);
        
        Dictionary<string, int> map = new Dictionary<string, int>();
   
        string sa =sr.ReadToEnd();
        
        string[] sb =sa.Split(' '); //separator

        for(int i=0;i<sb.Length;++i)
        {
        	if (!map.ContainsKey(sb[i]))
        		map.Add(sb[i],1);
        	else{
        		
        		map[sb[i]] +=1;
        	}
        }
        //sort & show
		var srtmap=map.OrderByDescending(x=>x.Value);
		//Console.WriteLine(srtmap);
        	
        int order1=0;
        foreach (KeyValuePair<string, int> kvp in srtmap )
		{
		++order1;
    	Console.WriteLine("{0} {1}\t\t\t\t\t...{2}", order1, kvp.Key, kvp.Value);
		}
	}
	}
}