// https://omegaup.com/problem/uacj21-tiendas

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
	static class Mall {
		private final int maxMall;
		private final int maxPlace;
		private final Set<String> badPlaces;
		private final Map<String, Integer> placeCounts;
		private int mallTotalCount;
		private int mallCount;
		private boolean error;
		
		Mall(int maxMall, int maxPlace) {
			this.maxMall = maxMall;
			this.maxPlace = maxPlace;
			badPlaces = new HashSet<String>();
			placeCounts = new HashMap<String, Integer>();
			mallTotalCount = 0;
			mallCount = 0;
			error = false;
		}
		
		boolean log(int n, boolean out, String place) {
			if ("centro-comercial".equals(place)) {
				if (out) {
					mallTotalCount -= n;
					mallCount -= n;
					if (mallTotalCount < 0 || mallCount < 0) {
						error = true;
					}
				} else {
					mallTotalCount += n;
					mallCount += n;
					if (maxMall < mallTotalCount) {
						badPlaces.add(place);
					}
				}
			} else {
				int count = placeCounts.getOrDefault(place, 0);
				if (out) {
					count -= n;
					mallCount += n;
					if (count < 0) {
						error = true;
					}
				} else {
					count += n;
					mallCount -= n;
					if (maxPlace < count) {
						badPlaces.add(place);
					}
					if (mallCount < 0) {
						error = true;
					}
				}
				placeCounts.put(place, count);
			}
			return error;
		}
		
		void report() {
			if (error) {
				System.out.println("ERROR");
			} else if (badPlaces.isEmpty()) {
				System.out.println("OK");
			} else {
				List<String> list = new ArrayList<String>(badPlaces);
				Collections.sort(list);
				for (String l : list) {
					System.out.println(l + " ");
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Mall mall = new Mall(in.nextInt(), in.nextInt());
		for (int i = in.nextInt(); 0 < i; --i) {
			int n = in.nextInt();
			boolean out = "salir".equals(in.next());
			String place = in.next();
			if (mall.log(n, out, place)) {
				break;
			}
		}
		mall.report();
		in.close();
	}
}
