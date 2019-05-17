import java.util.*;
public class 앉았다 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int d[]=new int[11];
		double ans=0;
		int cnt=0;
		for(int i=1;i<11;i++) {
			d[i]=2;
		}
		d[a]--;d[b]--;
		if(a==b) {
			cnt=a+10;
		}else {
			int temp=a+b;
			String s=Integer.toString(temp);
			char c=s.charAt(s.length()-1);
			cnt=c-'0';
		}
		for(int i=1;i<11;i++) {
			for(int j=i;j<11;j++) {
				if(i==j) {
					if(d[i]==2) {
						if(i+10<cnt) {
							ans+=1.0;
						}
					}
					else {
						continue;
					}
				}else {
					if(d[i]>=1&&d[j]>=1) {
						int temp=i+j;
						String s=Integer.toString(temp);
						char c=s.charAt(s.length()-1);
						if(c-'0'<cnt) {
							if(d[i]+d[j]==2) {
								ans+=1.0;
							}else if(d[i]+d[j]==3) {
								ans+=2.0;
							}else {
								ans+=4.0;
							}
						}
					}
				}
			}
		}
		ans/=153.0;
		System.out.println(String.format("%.3f", ans));
		
	}

}
