package 백준;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class 집합11723번 {

	public static void main(String[] args)throws IOException {
		Set set = new HashSet();
		Set set2= new HashSet();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=1;i<21;i++) {
			set2.add(i);
		}
		
		int n = Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++) {
			String[] x= br.readLine().split(" ");
			
			if(x[0].equals("add")) {
				set.add(x[1]);
			}
			else if(x[0].equals("remove")) {
				set.remove(x[1]);
			}
			else if(x[0].equals("check")) {
				if(set.contains(x[1])) {
					System.out.println("1");
				}
				else {
					System.out.println("0");
				}
			}
			else if(x[0].equals("toggle")) {
				if(set.contains(x[1])) set.remove(x[1]);
				else set.add(x[1]);
			}
			else if(x[0].equals("all")) {
				set.clear();
				set.addAll(set2);
			}
			else if(x[0].equals("empty")) {
				set.clear();
			}
		}


	}

}