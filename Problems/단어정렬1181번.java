package 백준;

import java.util.*;
public class 단어정렬1181번{
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int n=sc.nextInt();
		String a[]=new String[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.next();
		}
		Arrays.sort(a,new sort());
		System.out.println(a[0]);
		for(int i=1;i<a.length;i++) {
			if(a[i-1].equals(a[i])) {
				continue;
			}
			System.out.println(a[i]);
		}
		
	}

	
	}

class sort implements Comparator<String>{
	@Override
	public int compare(String o1, String o2) {
		if(o1.length()>o2.length()) {
			return 1;
		}else if(o1.length()<o2.length()){
			return -1;
		}
		else {

			if(o1.compareTo(o2)>0) {
				return 1;
			}else if(o1.compareTo(o2)<0) {
				return -1;
			}else {
			return 0;
			}
		}
	}
}