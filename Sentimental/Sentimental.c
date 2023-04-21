#include <stdio.h>
#include <string.h>


char* find_intent(char* sentence) {
    
    char* positive_words[] =  {"happy", "great", "good", "excellent", "wonderful", "fantastic", "awesome", "love", "like", "enjoy"};
    char* negative_words[] =  {"sad", "bad", "terrible", "awful", "hate", "dislike", "disappoint", "frustrate", "annoy", "upset"};
    int positive_words_count = 10;
    int negative_words_count = 10;

   
    char* token = strtok(sentence, " ");
    int positive_score = 0;
    int negative_score = 0;
    while (token != NULL) {
       
        for (int i = 0; i < positive_words_count; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_score++;
                break;
            }
        }

        for (int i = 0; i < negative_words_count; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_score++;
                break;
            }
        }

       
        token = strtok(NULL, " ");
    }

   
    int sentiment_score = positive_score - negative_score;

    
    if (sentiment_score > 0) {
        return "Positive";
    } else if (sentiment_score < 0) {
        return "Negative";
    } else {
        return "Neutral";
    }
}

int main() {
    char sentence[256];
    printf("Enter a sentence: ");
    fgets(sentence, 256, stdin);
    sentence[strcspn(sentence, "\n")] = 0; 
  
    char* intent = find_intent(sentence);

  
    printf("The intent of the sentence is %s\n", intent);
    return 0;
}
