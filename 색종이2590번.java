package 백준;
import java.util.*;
public class 색종이2590번 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int d[]=new int[7];
		int ans=0;
		for(int i=1;i<=6;i++) {
			d[i]=sc.nextInt();
		}
		ans+=d[6];
		d[6]=0;
		
		ans+=d[5];
		if(d[1]>=d[5]*11) {
			d[1]-=d[5]*11;
		}
		else {
			d[1]=0;
		}
		d[5]=0;
		
		for(int i=0;i<d[4];i++) {
			ans++;
			int n=20;
			if(d[2]>=5) {
				d[2]-=5;
			}else {
				n-=d[2]*4;
				d[2]=0;
				if(0<n&&n<=d[1]) {
					d[1]-=n;
				}else if(0<n&&n>d[1]) {
					d[1]=0;
				}
			}
		}
		d[4]=0;
		
		int k=(int)Math.ceil(d[3]/4.0);
		ans+=k;
		k=d[3]%4;
		if(k!=0) {
		if(k==1) {
			int k1=5;
			int k2=7;
			if(k1<=d[2]) {
				d[2]-=k1;
			}else {
				k1-=d[2];
				d[2]=0;
				k2+=k1*4;
			}
			if(k2<d[1]) {
				d[1]-=k2;
			}else {
				d[1]=0;
			}
		}else if(k==2) {
			int k1=3;
			int k2=6;
			if(k1<=d[2]) {
				d[2]-=k1;
			}else {
				k1-=d[2];
				d[2]=0;
				k2+=k1*4;
			}
			if(k2<d[1]) {
				d[1]-=k2;
			}else {
				d[1]=0;
			}
		}else if(k==3) {
			int k1=1;
			int k2=5;
			if(k1<=d[2]) {
				d[2]-=k1;
			}else {
				k1-=d[2];
				d[2]=0;
				k2+=k1*4;
			}
			if(k2<d[1]) {
				d[1]-=k2;
			}else {
				d[1]=0;
			}
		}
		}
		
		k=(int)Math.ceil(d[2]/9.0);
		ans+=k;
		k=d[2]%9;
		int a=36-k*4;
		if(a<=d[1]&&k!=0) {
			d[1]-=a;
			}else if(a!=36&&k!=0){
			d[1]=0;
		}
		k=(int)Math.ceil(d[1]/36.0);
		ans+=k;
		k=d[1]%36;
		if(k==0) {
			d[1]=0;
		}else {
			ans++;;
		}
		System.out.println(ans);
	}

}
