import math
from typing import List

class DisInfo:
    def __init__(self, point, distance) -> None:
        self.point = point
        self.distance = distance
        
class Solution(object):
    def __init__(self) -> None:
        self.distances: List[DisInfo] = []
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
    
        result = []
        # calculate the distance from the start point to the other points.
        for p in points:
            self.distances.append(DisInfo(p ,self.caluate_distance((0,0), p)))
            # insert the calculated distance to heap. 
            self.insert_into_heap()

        for n in range(0, k):
            result.append(self.get_min())
            self.delete_from_heap()

        return result
    def caluate_distance(self, sor_point, dis_point) -> int:
        return math.sqrt(math.pow(sor_point[0] - dis_point[0], 2) + math.pow(sor_point[1] - dis_point[1], 2))

    def insert_into_heap(self):
        inserted_node_position = len(self.distances)
        # get the parent of the appended node.
        parent_heap = int(inserted_node_position / 2)
        while( inserted_node_position > 1 
            and self.need_swap(parent_heap)):
            self.swap(inserted_node_position , parent_heap)
            inserted_node_position = parent_heap
            parent_heap = int(parent_heap / 2)
    
    def get_min(self):
        return self.distances[0].point

    def delete_from_heap(self):
        if not self.is_heap_empty():
            # swap last element with peak 
            self.swap(len(self.distances) , 1)
            # remove the last element
            self.distances.remove(self.distances[len(self.distances)-1])
            self.restore_heap(1)
            

        #  comapre root with left and right.

        # if one of them less than the root swap.
        # repeat in

    # is right node exist
    def is_right_node_exist(self, parent_node):
        right = parent_node * 2 
        return (len(self.distances) - 1 >= right)

    def restore_heap(self, parent_node):
        left = parent_node * 2 
        right = parent_node * 2 + 1
        
        if not self.parent_has_childs(parent_node): return
        if self.is_right_node_exist(parent_node):
            if (self.distances[parent_node - 1].distance < self.distances[left-1].distance 
            and self.distances[parent_node - 1].distance < self.distances[right-1].distance):
                return 
        elif( self.distances[parent_node - 1].distance < self.distances[left-1].distance):
            return 


        # right node not exist:
        if self.is_right_node_exist(parent_node):
            if (self.distances[left - 1 ].distance < self.distances[right - 1 ].distance):
                self.swap(parent_node , left)
                self.restore_heap(left)
            else:
                self.swap(parent_node, right)
                self.restore_heap(right)
        else: 
            self.swap(parent_node , left)
    
    def is_heap_empty(self): 
        return len(self.distances) == 0 
    
    def parent_has_childs(self, parent_node):
        index_of_left_child = parent_node * 2 - 1
        index_of_right_child = parent_node * 2
        heap_lenght = len(self.distances) - 1
        return index_of_left_child <= heap_lenght or index_of_right_child <= heap_lenght

    def need_swap(self, parent):
        index_of_parent = parent - 1
        index_of_left_child = parent * 2 - 1
        index_of_right_child = parent * 2
        if (( index_of_left_child <= len(self.distances) - 1 and self.distances[index_of_parent].distance > self.distances[index_of_left_child].distance) 
            or ( index_of_right_child <= len(self.distances) - 1 and self.distances[index_of_parent].distance > self.distances[index_of_right_child].distance)):
            return True
        return False
        # loop over the heap with k value
            # restore the heap  
    

    
    def swap(self, s1 , s2):
        temp = self.distances[s1-1]
        self.distances[s1 - 1] = self.distances[s2-1]
        self.distances[s2 - 1] = temp
