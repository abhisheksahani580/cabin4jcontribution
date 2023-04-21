import heapq
from collections import defaultdict


class Autocomplete:
    def __init__(self, file_path):
        self.words = defaultdict(dict)
        with open(file_path, 'r', encoding='utf-8') as f:
            for line in f:
                values = line.strip().split()
                if len(values) <2:
                    continue
                try:
                    weight = float(values[0])
                except ValueError:
                    continue
                word = ' '.join(values[1:])
                self.words[word[0]][word] = weight
    def autocomplete(self, prefix, k):
        suggestions = []
        if prefix in self.words:
            heap = [(-weight, word) for word, weight in self.words[prefix].items()]
            largest = heapq.nlargest(k, heap)
            suggestions = [word for weight, word in largest]
        return suggestions

    def run(self):
        while True:
            prefix = input('Enter a prefix: ')
            if not prefix:
                break
            k = int(input('Enter k: '))
            suggestions = self.autocomplete(prefix, k)
            print(suggestions)


if __name__ == '__main__':
    file_path = 'file.txt'

    autocomplete = Autocomplete(file_path)
    autocomplete.run()