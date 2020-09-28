import java.util.*;
public class 용감한용사진수 {
	static int ans=100000000;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		Sat s[]=new Sat[n];
		Sat all[]=new Sat[(int)Math.pow(n, 3)];
		for(int i=0;i<n;i++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			s[i]=new Sat(x, y, z);
		}
		int cnt=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int l=0;l<n;l++) {
					all[cnt++]=new Sat(s[i].x, s[j].y, s[l].z);
				}
			}
		}
		for(int i=0;i<(int)Math.pow(n, 3);i++) {
			
			int p=0;
			int temp=all[i].x+all[i].y+all[i].z;
			for(int j=0;j<n;j++) {
				if(all[i].x>=s[j].x&&all[i].y>=s[j].y&&all[i].z>=s[j].z) {
					p++;
				}
			}
			if(p>=k) {
				ans=Math.min(ans, temp);
			}
		}
		System.out.println(ans);
		
	}

}

class Sat {
	int x;
	int y;
	int z;
	Sat(int x,int y,int z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
	
}