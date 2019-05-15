package 백준;
import java.util.*;
public class 숫자야구2503번 {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		St st[]=new St[n];
		int d[]=new int[1000];
		boolean p=false;
		int cnt=0;
		for(int i=0;i<n;i++) {
			String s=sc.nextLine();
			int a=sc.nextInt();
			int b=sc.nextInt();
			st[i]=new St(s,a,b,d,p);
		}
		for(int i=0;i<n;i++) {
			st[i].sort();
			if(i==0)
				p=true;
		}
		for(int i=111;i<=999;i++) {
			String s1=Integer.toString(i);
			for(int j=0;j<3;j++) {
				if(s1.charAt(j)!=0) {}
			}
			if(d[i]==1&&s1.charAt(0)!=0&&s1.charAt(1)!=0&&s1.charAt(2)!=0) 
				cnt++;
		}
		System.out.println(cnt);
	}

}
class St{
	boolean p;
	String num;
	int s;
	int b;
	int d[];
	St(String num,int s,int b,int[] d,boolean p){
		this.num=num;
		this.s=s;
		this.b=b;
		this.d=d;
		this.p=p;
	}
	public void sort() {
		if(s==0) {
			if(b==0)
				for(int i=111;i<d.length;i++) {
					String s1=Integer.toString(i);
					for(int j=0;j<3;j++) {
					}
				}
		}
		else if(s==1) {
			if(b==0) {
				for(int i=111;i<d.length;i++) {
					String s1=Integer.toString(i);
					for(int j=0;j<3;j++) {
						if(s1.charAt(j)==num.charAt(j)) {
							if(p==false) {
								d[i]=1;
							}
						}else {
							d[i]=0;
						}
					}
				}
			}else if(b==1) {
				for(int i=111;i<d.length;i++) {
					String s1=Integer.toString(i);
					for(int j=0;j<3;j++) {
						if(s1.charAt(j)==num.charAt(j)&&s1.charAt((j+1)%3)==num.charAt((j+2)%3)){
							if(p==false)
								d[i]=1;
						}else if(s1.charAt(j)==num.charAt(j)&&s1.charAt((j+2)%3)==num.charAt((j+1)%3)) {
							if(p==false)
								d[i]=1;
						}else
							d[i]=0;					
						}
				}
			}else if(b==2) {
				for(int i=111;i<d.length;i++) {
					String s1=Integer.toString(i);
					for(int j=0;j<3;j++) {
						if(s1.charAt(j)==num.charAt(j)&&s1.charAt((j+1)%3)==num.charAt((j+2)%3)&&s1.charAt((j+2)%3)==num.charAt((j+1)%3)){
							if(p==false)
								d[i]=1;
						}else {
							d[i]=0;	
						}				
					}
				}
			}
		}
		else if(s==2) {
			for(int i=111;i<d.length;i++) {
				String s1=Integer.toString(i);
				for(int j=0;j<3;j++) {
					if(s1.charAt(j)==num.charAt(j)&&s1.charAt(j%3+1)==s1.charAt(j%3+1)) {
						if(p==false) {
							d[i]=1;
						}
					}else if(s1.charAt(j)==num.charAt(j)&&s1.charAt(j%3+2)==s1.charAt(j%3+2)) {
						if(p==false) {
							d[i]=1;
						}
					}else {
						d[i]=0;
					}
				}
			}
		}else {
			System.out.println(1);
			System.exit(0);
		}
	}
}