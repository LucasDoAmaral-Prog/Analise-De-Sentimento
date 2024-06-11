<h1>Análise de Sentimento</h1>

<h3>Contextualização do projeto</h3>
<p>Mineração de dados é um campo interdisciplinar que combina, por exemplo, processamento de dados, estatística e inteligência artificial para identificar padrões e extrair insights normalmente invisíveis, mas presentes em bases de dados. Enquanto a mineração de bases de dados numéricos ou já bem estruturados (como em planilhas, por exemplo) é relativamente mais fácil, a mineração de dados textuais, especialmente texto em linguagem natural, como o encontrado em redes sociais, envolve um conjunto diferente de desafios.
Uma aplicação popular da mineração de texto é a análise de sentimento, na qual palavras e frases são identificadas para classificar, por exemplo, a polaridade de um documento, ou seja, se a opinião expressa é positiva, neutra ou negativa.</p><br>
<p>Portanto, o desafio dado foi: Neste trabalho, você deverá escrever um programa que receba um texto e duas listas de palavras, uma com palavras consideradas positivas e a outra com palavras consideradas negativas, para responder diferentes questões sobre a polaridade expressa no documento. Tal texto possuirá até 10 parágrafos, com até 20 sentenças por parágrafo, até 70 palavras por sentença e com até 20 letras por palavra, mas não utrapassando o total de 9040 caracteres (incluindo-se os caracteres especiais '\n' e '\0'). São consideradas como palavras qualquer sequência de letras que precedam um espaço em branco (" ") ou ponto final ("."). São consideradas como sentenças qualquer sequência de palavras que precedam um ponto final ("."). São considerados como parágrafos qualquer sequência de sentenças que precedam um "\n". Por fim, é considerado como texto qualquer sequência de parágrafos.</p>
<br>
<h3>Estrutura do input:</h3>
<p>
1. Quantidade de parágrafos que serão fornecidos;
2. Texto (parágrafos);
3. Lista de palavras positivas separadas por espaços, todas em uma só linha;
4. Lista de palavras negativas separadas por espaços, todas em uma só linha;
5. Quantidade de questões a serem respondidas;
6. Questões, uma por linha.
Existem 4 questões possíveis, cada uma identificada por um número de 1 a 4. São elas:

1 - Determine a polaridade do texto;
2 i - Determine a polaridade do parágrafo i (sendo i um valor de 0 a 9 correspondente ao respectivo parágrafo);
3 - Determine a polaridade da sentença mais longa considerando a quantidade de caracteres nas palavras da sentença;
4 - Determine a polaridade da sentença mais curta considerando a quantidade de palavras na sentença.
</p>
<br>
<h3>Exemplos de input, junto com o output</h3>
<p color: blue>
<h1>INPUT</h1>
2
Like Xenogears, you also pilot mechs though they are less important in this game, and are more a background theme than being the focus. Music was done by Yasunori Mitsuda and performed by the London Philharmonic Orchestra and it definitely shows. While much of the game is just ambient sounds, whenever the music does take over it brings with it the magic of what a truly well-composed and performed orchestrated soundtrack can do for a game. The graphics are well done, and animated very smoothly and the effects during battles are very pretty. Being a little older than some recent RPG's (Was released over a year ago in Japan and the translation took forever) the graphics seem slightly dated but they are still beautiful.
And now the bad news: For me this game possesses only one flaw in that the English dubbing of it is only average, sounding like a dubbed anime. Many characters are over acting and it pains me to see this in such a quality RPG. It doesn't help that during the cut scenes the dialogue is subtitled right along with the actors speaking the same language which would be fine if they sounded better, but since they don't it's annoying to read it before they say it, and hear them say it with forced emotion or non at all. It is a minor flaw in a near flawless RPG. The other concern is the editing. There is one cut scene that was altered and it only involves the placement of a hand. Nothing to worry about.
well important magic well-composed smoothly beautiful flawless quality fine
less background average overacting pains annoying forced concern altered worry
2
2 0
2 1
</p>
<p color: red>
<h1>OUTPUT</h1>
6 Palavras positivas, 2 Palavras negativas: Polaridade positiva
3 Palavras positivas, 9 Palavras negativas: Polaridade negativa</p>
