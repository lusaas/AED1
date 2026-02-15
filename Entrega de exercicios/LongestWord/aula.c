char **result(char **dictionary, int dictionarySize) {
    for (int w = 0; w < dictionarySize; w++) {
        char *temp = dictionary[w];
        int j = w - 1;

        while(j >= 0 && strcmp(dictionary[j], temp) > 0) {
			dictionary[j + 1] = dictionary[j];
			j--;
        }
       dictionary[j + 1] = temp;
    }
    return dictionary;
}

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    int sLength = strlen(s);

    char **order = result(dictionary, dictionarySize);

    for (int i = 0; i < sLength; i++) {
        char temp = s[i];
        int j = i - 1;

        while(j >= 0 && s[j] > temp) {
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = temp;
    }

    int w = 0, m = 0, n = 0;
    char **word = (char **)malloc(100 * sizeof(char *));

    for (int i = 0; i < dictionarySize; i++) {
        int wordLength = strlen(dictionary[i]);
        for (int j = 0; j < sLength; j++) {
            if (order[i][m] == s[j]) {
                word[n][w] = order[i][m];
                w++;
                m++;
            } else {
                m++;
            }
            if (w == wordLength) {
                break;
            }
        }
        if (word[n] == order[i]) {
            n++;
        }
    }

    if (strlen(word) == 1) {
        return *word;
    } else {
        for (int i = 0; i < strlen(word); i++) {
            if (strlen(word[i]) < strlen(word[i + 1])) {
                return word[i + 1];
            } else {
                return word[i];
            }
        }
    }
}
