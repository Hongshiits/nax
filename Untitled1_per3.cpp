#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
//#include<map>

using namespace std;


//func

string h_asicll(vector<string> out_str){
	string a_str=out_str[0];
    int a=(int)a_str[0];
    cout<<a<<endl;
    return "OK";
}
string h_print(vector<string> out_str){
    cout<<out_str[0]<<endl;
    return "OK";
}
string h_erro(vector<string>){
	cout<<"erro"<<endl;
	string cont_if;
	cin>>cont_if;
	if(cont_if=="Y"){
		return "OK";
	}else{
		return 0;
	}
	return "OK";
}

//map

/*
map<string,long> base_func; //64bit processor use long
int init_map(){
	//base_func.insert(pair<string,long>("print",(long)h_print));
	//base_func.insert(pair<string,long>("asicll",(long)h_asicll));

}
*/
//fail to use map

vector<string> base_func_name;
vector<long> base_func_addr;
int init_map(){
	base_func_name.push_back("print");
	base_func_addr.push_back((long)h_print);

	base_func_name.push_back("asicll");
	base_func_addr.push_back((long)h_asicll);
	
	base_func_name.push_back("erro");
	base_func_addr.push_back((long)h_erro);
	return 100;
}

//finder
long back_addr=0;
long horn_finder(vector<string> func_name){
    
	for(int i=0;i<base_func_name.size();i++){
		string find_func_name_temp=base_func_name[i];
		if(func_name[0]==find_func_name_temp){
			back_addr=base_func_addr[i];
		}
		return back_addr;
	}


	/*
	const string inner_test=func_name[0];
	cout<<"test"<<inner_test<<endl;
	string func_str_in=inner_test;

	return base_func[func_str_in];
	 if(func_name.size()>1){
	 	cout<<"no finder";
	 	return (long)h_erro;
	 }else{
	 	string name=func_name[0];
	 	map<string,long>::iterator it=base_func.find(name);
    	if(it!=base_func.end()){
    		return it->second;
		}else{
			cout<<"no func"<<endl;
			return (long)h_erro;
		}
	 }
	 */
    //return h_print;
}

//split

vector<string> horn_split(string cm_str,const char *get_cut_str){
    vector<string> para_vstr;
    const char *cut_str=get_cut_str;
    int temp_ind=0,char_num_temp=0;
    string::iterator last_cm_str=cm_str.begin();
    while((cm_str.begin()+temp_ind-1)!=cm_str.end()){

        string temp_str;
        if(cm_str[temp_ind]!=cut_str[0]){
            temp_str.push_back(cm_str[temp_ind]);
            //cout<<cm_str[temp_ind]<<endl; //
            char_num_temp++;

        }
        else{
            string in_temp_str(last_cm_str,last_cm_str+char_num_temp);
            para_vstr.insert(para_vstr.end(),in_temp_str);
            last_cm_str=last_cm_str+char_num_temp+1;
            char_num_temp=0;

        }
        if((cm_str.begin()+temp_ind)==cm_str.end()){
            string in_temp_str(last_cm_str,last_cm_str+char_num_temp);
            char_num_temp=0;
            para_vstr.insert(para_vstr.end(),in_temp_str);
        }

        temp_ind++;
    }

    //cout<<para_vstr.size()<<endl;
    /*
    for(int i=0;i<para_vstr.size();i++){
        cout<<"vstr "<<para_vstr[i]<<endl;
    }
    */
    return para_vstr;
}

//shell (entrence)

int shell(string cm_shell_str){
	
	
	
	
    vector<string> cm_shell_vec(horn_split(cm_shell_str," "));
    vector<string> cm_funcname_vec(horn_split(cm_shell_vec[0],"."));
    vector<string> cm_para_vec(cm_shell_vec.begin()+1,cm_shell_vec.end());

    for(int i=0;i<cm_para_vec.size();i++){
        cout<<"vstr "<<cm_para_vec[i]<<endl;
    }
    //horn_finder(cm_funcname_vec); 
    
    string addr_str=cm_funcname_vec[0];
    back_addr=atoi(addr_str.c_str());
    
    cout<<"exe func addr"<<back_addr<<endl;
	string (*execute_func)(vector<string>)=(string (*)(vector<string>))back_addr;
    string func_back=execute_func(cm_para_vec);
    cout<<"func message:"<<func_back<<endl;


}

int main(){
	
	
	
	cout<<init_map()<<endl;
	
	cout<<"func menu"<<endl;
	for(int i=0;i<base_func_name.size();i++){
		
		cout<<base_func_name[i]<<" "<<base_func_addr[i]<<endl;
	}


	while(1){
    string cm_str;
    cout<<(long)shell<<"<";
    getline(cin,cm_str);
    cout<<"cmd:"<<cm_str<<endl;
    shell(cm_str);
	}
    return 0;
}

