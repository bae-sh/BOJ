package 백준;

import java.util.*;
public class 나이순정렬10814번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Person2 p[]= new Person2[n];
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			String name=sc.next();
			p[i]=new Person2(a,name);
		}
		Arrays.sort(p);
		for(int i=0;i<n;i++) {
			System.out.println(p[i].x+" "+p[i].name);
		}
	}

}
class Person2 implements Comparable{
	int x=0;
	String name;
	Person2(int x,String name){
		this.x=x;
		this.name=name;
	}
	public int compareTo(Object obj) {
		Person2 other =(Person2)obj;
		if(x<other.x) {
			return -1;
		}
		else if(x>other.x) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
}