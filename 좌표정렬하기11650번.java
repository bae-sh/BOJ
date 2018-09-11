package 백준;

import java.util.*;
public class 좌표정렬하기11650번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Person p[]=new Person[n];
		for(int i=0;i<n;i++) {
			
			int a=sc.nextInt();
			int b=sc.nextInt();
			p[i]=new Person(a,b);
		}
		Arrays.sort(p);
		for(int i=0;i<n;i++) {
			System.out.println(p[i].x+" "+p[i].y);
		}
	}

}
class Person implements Comparable{
	int x=0;
	int y=0;
	Person(int x,int y){
		this.x=x;
		this.y=y;
	}
	public int compareTo(Object obj) {
		Person other =(Person)obj;
		if(x<other.x) {
			return -1;
		}
		else if(x>other.x) {
			return 1;
		}
		else {
			if(y<other.y) {
				return -1;
			}
			else if(y>other.y) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	
}
