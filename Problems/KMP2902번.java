package 백준;
import java.io.*;
import java.util.*;
public class KMP2902번 {

	public static void main(String[] args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String a[]=br.readLine().split("-");
		for(int i=0;i<a.length;i++) {
			System.out.print(a[i].charAt(0));
		}
	}

}
