#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

struct question{
	string a, b, c;
	question(){}
	question(string a, string b, string c):a(a), b(b), c(c){}
};

string a[8][8];

signed main(){
	srand(time(0));
	ifstream in;
	in.open("frenchverb");
	for(int i=0; i<8; ++i)for(int j=0; j<8; ++j){
		in>>a[i][j];
	}
	vector<question> p;
	for(int i=1; i<8; ++i)for(int j=2; j<8; ++j)p.push_back(question(a[0][j], a[i][1], a[i][j]));
	//for(auto i:p)cout<<i.a<<' '<<i.b<<' '<<i.c<<endl;
	timeval st; gettimeofday(&st, NULL);
	while(p.size()){
		random_shuffle(p.begin(), p.end());
		auto ans=p[p.size()-1];
		bool ok;
		cout<<ans.a<<' '<<ans.b<<' ';
		string s; cin>>s;
		ok=s==ans.c;
		timeval ed; gettimeofday(&ed, NULL);
		gettimeofday(&ed, NULL), ed.tv_sec-=st.tv_sec, ed.tv_usec-=st.tv_usec;
		if(ed.tv_usec<0)--ed.tv_sec, ed.tv_usec+=1000000;
		cout<<(ok?"Correct":"Wrong")<<", time: "<<(long long)(ed.tv_sec*1000000+ed.tv_usec)<<endl;
		if(!ok)cout<<ans.c<<endl;
		if(ok)p.pop_back();
		else p.push_back(ans);
	}
}
