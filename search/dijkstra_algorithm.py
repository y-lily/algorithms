from __future__ import annotations

import math
from abc import ABC, abstractmethod, abstractproperty
from typing import Optional


class Node(ABC):

    _previous: Optional[Node] = None
    _tentative_distance = math.inf

    @abstractproperty
    def neighbours(self) -> set[Node]: pass

    @abstractmethod
    def distance(self, to_node: Node) -> float: pass

    @property
    def previous(self) -> Optional[Node]:
        return self._previous

    @property
    def tentative_distance(self) -> float:
        return self._tentative_distance

    def relax_tentative_distance(self, through_node: Node) -> bool:
        new_distance = through_node.tentative_distance + \
            through_node.distance(self)

        if new_distance >= self._tentative_distance:
            return False

        self._tentative_distance = new_distance
        self._previous = through_node
        return True

    def set_as_source(self) -> None:
        self._tentative_distance = 0


class DistanceFinder:

    visited: set[Node]
    visit_queue: list[Node]

    def calculate_shortest_distance(self, start: Node, end: Node) -> float:
        self._reset(start)

        while self.visit_queue:
            node = self.visit_queue[0]

            if node is end:
                break

            self._visit(node)

        return end.tentative_distance

    def calculate_tentative_distances(self, source: Node) -> None:
        self._reset(source)

        while self.visit_queue:
            node = self.visit_queue[0]
            self._visit(node)

    def _add_to_visit_queue(self, node: Node, sort: bool) -> None:
        if node not in self.visit_queue:
            self.visit_queue.append(node)

        if sort:
            self.visit_queue.sort(key=lambda node: node.tentative_distance)

    def _move_to_visited(self, node: Node) -> None:
        self.visit_queue.remove(node)
        self.visited.add(node)

    def _reset(self, source: Node) -> None:
        self.visited = set()
        self.visit_queue = []

        source.set_as_source()
        self.visit_queue.append(source)

    def _visit(self, node: Node) -> None:
        for neighbour in node.neighbours:
            relax_successful = neighbour.relax_tentative_distance(node)

            if neighbour not in self.visited:
                self._add_to_visit_queue(neighbour, relax_successful)

        self._move_to_visited(node)
