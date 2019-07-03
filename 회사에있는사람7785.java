import java.util.*;
import java.io.*;
public class 회사에있는사람7785 {

	public static void main(String[] args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		HashSet<String> set=new HashSet<>();
		while(n-->0) {
			String[] s=br.readLine().split(" ");
			if(s[1].equals("enter")) {
				set.add(s[0]);
			}else {
				set.remove(s[0]);
			}
		}
		ArrayList<String> a=new ArrayList<>(set);
		Collections.sort(a);
		for(int i=a.size()-1;i>=0;i--) {
			System.out.println(a.get(i));
		}
	}

}
