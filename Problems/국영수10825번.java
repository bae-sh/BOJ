package 백준;

import java.util.*;
public class 국영수10825번 {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		int n=sc.nextInt();
		People p[]=new People[n];
		for(int i=0;i<n;i++) {
			String name=sc.next();
			int han=sc.nextInt();
			int English=sc.nextInt();
			int math=sc.nextInt();
			p[i]=new People(name,han,English,math);
		}
		Arrays.sort(p);
		for(int i=0;i<n;i++) {
			System.out.println(p[i].name);
		}
	}

}
class People implements Comparable{
	String name;
	int han;
	int math;
	int English;
	
	public People(String name,int han,int English,int math) {
		this.name=name;
		this.han=han;
		this.math=math;
		this.English=English;
	}

	@Override
	public int compareTo(Object o) {
		People other=(People)o;
		if(han<other.han) {
			return 1;
		}
		else if(han>other.han) {
			return -1;
		}
		else {
			if(English<other.English) {
				return -1;
			}
			else if(English>other.English) {
				return 1;
			}
			else {
				if(math<other.math) {
					return 1;
				}
				else if(math>other.math) {
					return -1;
				}
				else {
					if(name.compareTo(other.name)<0) {
						return -1;
					}
					else if(name.compareTo(other.name)>0) {
						return 1;
					}
					else {
						return 0;
					}
				}
			}
		}
	}
}
