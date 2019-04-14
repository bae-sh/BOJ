import java.util.*;
import java.io.*;
public class 롤러코스터2873번 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] s=br.readLine().split(" ");
		int r=Integer.parseInt(s[0]);
		int c=Integer.parseInt(s[1]);
		int a[][]=new int[r][c];
		int min=1000;
		P m=new P();
		String st="";
		for(int i=0;i<r;i++) {
			s=br.readLine().split(" ");
			for(int j=0;j<c;j++) {
				a[i][j]=Integer.parseInt(s[j]);
			}
		}
		if(r%2!=0||c%2!=0) {
			for(int j=0;j<r-1;j+=2) {
				for(int i=0;i<c-1;i++) {
				st+="R";
				}
				st+="D";
				for(int i=0;i<c-1;i++) {
					st+="L";
				}
				st+="D";
			}
			if(r%2!=0) {
				for(int i=0;i<c-1;i++) {
					st+="R";
					}
			}
		}
		else {
		for(int i=0;i<r;i++) {
			for(int j=(i+1)%2;j<c;j+=2) {
				if(min>a[i][j]) {
					min=a[i][j];
					m.x=i;
					m.y=j;
				}
			}
		}
		int x=0; int y=0;
		while(m.x-x>=2) {
			for(int i=0;i<c-1;i++) {
				st+="R";
			}
			st+="D";
			for(int i=0;i<c-1;i++) {
				st+="L";
			}
			st+="D";
			x+=2;
		}
		while(true) {
			if(m.y-y<=2) {
				if(m.y-y==1) {
					st+="DR";
					y+=1;
				}else if(m.y==y) {
					st+="RD";
					y+=1;
				}
				while(y!=c-1) {
					st+="RURD";
					y+=2;
				}
			}else {
				st+="DRU";
				y++;
				continue;
			}
			break;
		}
		x++;
		while(x!=r-1) {
			st+="D";
			for(int i=0;i<c-1;i++) {
				st+="L";
			}
			st+="D";
			for(int i=0;i<c-1;i++) {
				st+="R";
			}
			x+=2;
		}
	}
		System.out.println(st);
	}
}
class P{
	int x;
	int y;
}