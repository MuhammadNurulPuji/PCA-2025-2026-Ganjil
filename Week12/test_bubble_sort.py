import unittest
import sys
import os

# Add the current directory to sys.path to allow importing the module
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from bubble_sort_simulation import bubble_sort_simulation

class TestBubbleSort(unittest.TestCase):
    def test_random_unsorted_list(self):
        arr = [64, 34, 25, 12, 22, 11, 90]
        expected = sorted(arr)
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

    def test_already_sorted_list(self):
        arr = [1, 2, 3, 4, 5]
        expected = arr.copy()
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

    def test_reverse_sorted_list(self):
        arr = [5, 4, 3, 2, 1]
        expected = sorted(arr)
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

    def test_list_with_duplicates(self):
        arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
        expected = sorted(arr)
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

    def test_empty_list(self):
        arr = []
        expected = []
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

    def test_single_element_list(self):
        arr = [42]
        expected = [42]
        result = bubble_sort_simulation(arr.copy())
        self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()
