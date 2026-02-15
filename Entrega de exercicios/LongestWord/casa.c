bool find(char *word, char *s) {
    int i = 0, j = 0;
    for ( ; word[i] != '\0' && s[j] != '\0'; j++) {
        if (word[i] == s[j]) {
            i++;
        }
    }
    return word[i] == '\0';
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    char *finalWord = "";
    for (int i = 0; i < dictionarySize; i++) {
        char *word = dictionary[i];

        if (find(word, s)) {
            int length = strlen(word);
            int finalLength = strlen(finalWord);

            if (length > finalLength || (length == finalLength && strcmp(word, finalWord) < 0)) {
                finalWord = word;
            }
        }
    }
    return finalWord;
}