package 백준;
import java.util.*;
import java.io.*;

public class 집합11723번 {

	public static void main(String[] args)throws IOException {
		Set set = new HashSet();
		Set set2= new HashSet();
		Queue q= new LinkedList();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=1;i<21;i++) {
			set2.add(i);
		}
		
		int n = Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st = new StringTokenizer( br.readLine() );
			String x= st.nextToken();
			
			if(x.equals("add")) {
				int y= Integer.parseInt(st.nextToken());
				set.add(y);
			}
			else if(x.equals("remove")) {
				int y= Integer.parseInt(st.nextToken());
				set.remove(y);
			}
			else if(x.equals("check")) {
				int y= Integer.parseInt(st.nextToken());
				if(set.contains(y)) {
					q.offer("1");
				}
				else {
					q.offer("0");
				}
			}
			else if(x.equals("toggle")) {
				int y= Integer.parseInt(st.nextToken());
				if(set.contains(y)) set.remove(y);
				else set.add(y);
			}
			else if(x.equals("all")) {
				set.clear();
				set.addAll(set2);
			}
			else if(x.equals("empty")) {
				set.clear();
			}
		}
		Iterator it = q.iterator();
		
		while(it.hasNext()) {
			System.out.println(it.next());
		}

	}

}