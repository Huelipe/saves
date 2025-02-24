figure;
subplot(2,1,1);
plot(tempo, saida_MalhaAberta);
title('Gráfico malha aberta');
xlabel('Tempo(s)');
ylabel('Amplitude');

subplot(2,1,2);
plot(tempo, saida_MalhaFechada);
hold on
plot(tempo, referencia);
hold off
title('Gráfico malha fechada');
xlabel('Tempo(s)');
ylabel('Amplitude');

% -------------------------------------------------------

C = pid(3.32, 0.0241, 5.3);

numerador = [0 0 5.369]; 
denominador = [0 0 0 341.6 1]; 
G = tf(numerador, denominador);

L = series(C, G);
T = feedback(L, 1);

% Diagrama de Bode para malha aberta
figure;
bode(T);
grid on;
title('Diagrama de Bode - Malha Aberta');

% Diagrama de Bode para malha fechada
figure;
bode(L);
grid on;
title('Diagrama de Bode - Malha Fechada');