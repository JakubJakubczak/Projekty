nums12 = list()
class Solution(object):
    def findMedianSortedArrays( nums1, nums2):
        j = 0
        k = 0
        m = len(nums1)
        n = len(nums2)
        for i in range(0, m + n - 1):
            if nums1[j] >= nums2[k]:
                nums12.append(nums2[k])
                k += 1
                if k == n:
                    while j != m:
                        nums12.append(nums1[j])
                        j += 1
                    break
            else:
                nums12.append(nums1[j])
                j += 1
                if j == m:
                    while k != n:
                        nums12.append(nums2[k])
                        k += 1
                    break
        if len(nums12) % 2 == 1:
            return nums12[int(len(nums12) / 2)]
        else:
            return (nums12[int(len(nums12) / 2)] + nums12[int(len(nums12) / 2 - 1)]) / 2

sol = Solution
nums1 = [1, 2]
nums2 = [3,4]

val = sol.findMedianSortedArrays(nums1, nums2)

print(str(nums12))
print(str(val))




