% Carregar o áudio
[audio, Fs] = audioread('C:\Users\SeuUsuario\Etc\Audio.wav');
audio = mean(audio, 2); % Converter para mono se o áudio for estéreo
N = length(audio);
t = (0:N-1)/Fs; % Eixo de tempo

% Filtro passa-baixa
Fc_abaixo = 1000; % Frequência de corte
[b_abaixo, a_abaixo] = butter(4, Fc_abaixo/(Fs/2), 'low');

% Filtro passa-alta
Fc_alto = 1000; 
[b_alto, a_alto] = butter(4, Fc_alto/(Fs/2), 'high');

% Filtro passa-banda
Fc_band = [500 1500];
[b_band, a_band] = butter(4, Fc_band/(Fs/2), 'bandpass');

% Aplicar os filtros
audio_baixo = filter(b_abaixo, a_abaixo, audio);
audio_alto = filter(b_alto, a_alto, audio);
audio_band = filter(b_band, a_band, audio);

% Domínio da frequência
f = (0:N-1)*(Fs/N); % Eixo de frequência
audio_fft = abs(fft(audio));
audio_baixo_fft = abs(fft(audio_baixo));
audio_alto_fft = abs(fft(audio_alto));
audio_band_fft = abs(fft(audio_band));

% ----------------------------------------------------------------------------
% Gráficos no domínio do tempo
figure;
subplot(4,1,1);
plot(t, audio);
title('Sinal de Áudio Original no Domínio do Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(4,1,2);
plot(t, audio_baixo);
title('Sinal Filtrado Passa-Baixa no Domínio do Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(4,1,3);
plot(t, audio_alto);
title('Sinal Filtrado Passa-Alta no Domínio do Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

subplot(4,1,4);
plot(t, audio_band);
title('Sinal Filtrado Passa-Banda no Domínio do Tempo');
xlabel('Tempo (s)');
ylabel('Amplitude');

% ----------------------------------------------------------------------------
% Gráficos no domínio da frequência
figure;
subplot(4,1,1);
plot(f, 20*log10(audio_fft));
title('Espectro do Áudio Original');
xlabel('Frequência (Hz)');
ylabel('Magnitude (dB)');

subplot(4,1,2);
plot(f, 20*log10(audio_baixo_fft));
title('Espectro do Áudio Filtrado Passa-Baixa');
xlabel('Frequência (Hz)');
ylabel('Magnitude (dB)');

subplot(4,1,3);
plot(f, 20*log10(audio_alto_fft));
title('Espectro do Áudio Filtrado Passa-Alta');
xlabel('Frequência (Hz)');
ylabel('Magnitude (dB)');

subplot(4,1,4);
plot(f, 20*log10(audio_band_fft));
title('Espectro do Áudio Filtrado Passa-Banda');
xlabel('Frequência (Hz)');
ylabel('Magnitude (dB)');

% ----------------------------------------------------------------------------
% Reprodução dos áudios
sound(audio, Fs);
pause(N/Fs + 1);
sound(audio_baixo, Fs);
pause(N/Fs + 1);
sound(audio_alto, Fs);
pause(N/Fs + 1);
sound(audio_band, Fs);