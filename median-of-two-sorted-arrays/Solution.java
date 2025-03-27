class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double result = 0;

        List<Integer> mergedArray = new ArrayList<Integer>();

        boolean keepIterating = true;

        int pointerA = 0;
        int pointerB = 0;

        Integer elementA = null;
        Integer elementB = null;

        int m = nums1.length;
        int n = nums2.length;

        do {
            if (m == 0) {
                //System.out.println("nums1 is empty");
                for (int element:nums2) {
                    mergedArray.add(element);
                }
                break;
            }
            if (n == 0) {
                //System.out.println("nums2 is empty");
                for (int element:nums1) {
                    mergedArray.add(element);
                }
                break;
            }

            elementA = pointerA < nums1.length ? nums1[pointerA] : null;
            elementB = pointerB < nums2.length ? nums2[pointerB] : null;

            if (elementA == null && elementB == null) {
                break;
            }

            if (elementA == null) {
                mergedArray.add(elementB);
                pointerB++;
                continue;
            }

            if (elementB == null) {
                mergedArray.add(elementA);
                pointerA++;
                continue;
            }

            if (elementA < elementB) {
                mergedArray.add(elementA);
                pointerA++;
            } else {
                mergedArray.add(elementB);
                pointerB++;
            }
        } while (keepIterating);

        //System.out.println(mergedArray);

        int half = mergedArray.size() / 2;

        if (mergedArray.size() % 2 == 0) {
            int indexA = half - 1;
            int indexB = half;

            int a = mergedArray.get(indexA);
            int b = mergedArray.get(indexB);

            result = ((float)a + (float)b) / 2;
        } else {
            result = mergedArray.get(half);
        }

        return result;
    }
}
