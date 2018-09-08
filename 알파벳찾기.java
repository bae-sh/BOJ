package 백준;

import java.util.*;
import java.io.*;
public class 알파벳찾기 {

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int Alp[]= new int[26];
		char[] Al=br.readLine().toCharArray();
		for(int i=0;i<Alp.length;i++) {
			Alp[i]=-1;
		}
		for(int i=0;i<Al.length;i++) {
			if(i==0||(Alp[(int)(Al[i]-'a')]==-1&&(int)(Al[i]-'a')!=(int)(Al[0]-'a'))) {
			Alp[(int)(Al[i]-'a')]=i;
			}
		}
		for(int i:Alp) {
			System.out.print(i+" ");
		}

		
	}

}
