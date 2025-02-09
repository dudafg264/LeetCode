double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
    int counter_students = 0, indice;
    float rates[classesSize], difference, average_pass_ratio = 0, max_diff;

    for (int i = 0; i < classesSize; i++) {
        rates[i] = (float)classes[i][0] / (float)classes[i][1];
        average_pass_ratio += rates[i];
    }

    float differences[classesSize];
    for (int i = 0; i < classesSize; i++) {
        differences[i] = ((float)(classes[i][0] + 1) / (float)(classes[i][1] + 1)) - rates[i];
    }

    while (counter_students < extraStudents) {
        max_diff = -1;

        for (int e = 0; e < classesSize; e++) {
            if (differences[e] > max_diff) {
                max_diff = differences[e];
                indice = e;
            }
        }

        average_pass_ratio -= rates[indice];
        rates[indice] = (float)(classes[indice][0] + 1) / (float)(classes[indice][1] + 1);
        average_pass_ratio += rates[indice];

        classes[indice][0] += 1;
        classes[indice][1] += 1;
        differences[indice] = ((float)(classes[indice][0] + 1) / (float)(classes[indice][1] + 1)) - rates[indice];

        counter_students++;
    }

    return average_pass_ratio / classesSize;
}

int main() {
    int classesSize, extraStudents;

    printf("Digite o número de classes: ");
    scanf("%d", &classesSize);

    int* classes[classesSize];
    int classesColSize[classesSize];

    for (int i = 0; i < classesSize; i++) {
        printf("Classe %d:\n", i + 1);
        classesColSize[i] = 2;

        classes[i] = (int*)malloc(classesColSize[i] * sizeof(int));

        printf("Digite o número de alunos aprovados: ");
        scanf("%d", &classes[i][0]);

        printf("Digite o número total de alunos: ");
        scanf("%d", &classes[i][1]);
    }

    printf("Digite o número de alunos extras: ");
    scanf("%d", &extraStudents);

    double result = maxAverageRatio(classes, classesSize, classesColSize, extraStudents);
    printf("Resultado da média máxima: %.6f\n", result);

    for (int i = 0; i < classesSize; i++) {
        free(classes[i]);
    }

    return 0;
}