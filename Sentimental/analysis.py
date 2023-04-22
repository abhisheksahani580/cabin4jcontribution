import os

def find_intent(sentence):
    positive_words = []
    negative_words = []

    # read positive words from file
    if os.path.exists("positive_words.txt"):
        with open("positive_words.txt", "r") as f:
            positive_words = [line.strip() for line in f.readlines()]

    # read negative words from file
    if os.path.exists("negative_words.txt"):
        with open("negative_words.txt", "r") as f:
            negative_words = [line.strip() for line in f.readlines()]

    positive_words_count = len(positive_words)
    negative_words_count = len(negative_words)

    tokens = sentence.split(" ")
    positive_score = 0
    negative_score = 0

    for token in tokens:
        if token in positive_words:
            positive_score += 1
        elif token in negative_words:
            negative_score += 1

    sentiment_score = positive_score - negative_score

    if sentiment_score > 0:
        return "Positive"
    elif sentiment_score < 0:
        return "Negative"
    else:
        return "Neutral"

sentence = input("Enter a sentence: ")
intent = find_intent(sentence)
print("The intent of the sentence is", intent)
