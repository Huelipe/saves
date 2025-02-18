-- Consulta para listar todos os proprietários com nome começando com 'Carlos' e ordenados por nome
SELECT * FROM proprietarios
WHERE nome LIKE 'Carlos%'
ORDER BY nome;

-- Consulta para listar todos os corretores com telefone que contém '11' e ordenados por telefone
SELECT * FROM corretores
WHERE telefone LIKE '%11%'
ORDER BY telefone;

-- Consulta para listar imóveis com valor acima de 100000.00 e ordenados por valor decrescente
SELECT * FROM imoveis
WHERE valor > 100000.00
ORDER BY valor DESC;

-- Consulta para listar inquilinos que têm telefone que começa com '11' e ordenados por nome
SELECT * FROM inquilinos
WHERE telefone LIKE '11%'
ORDER BY nome;

-- Consulta para calcular a média do valor do aluguel por imóvel, agrupado pelo tipo de imóvel
-- Objetivo: Esta consulta nos mostra a média do valor do aluguel por tipo de imóvel
SELECT tipo, AVG(valor_aluguel) AS media_aluguel
FROM alugueis
GROUP BY tipo;

-- Consulta para mostrar o nome dos corretores e os imóveis que estão sendo alugados, usando INNER JOIN
-- Objetivo: Esta consulta mostra os corretores e os imóveis que estão sendo alugados por inquilinos
SELECT corretores.nome AS corretor, imoveis.endereco AS imovel
FROM corretores
INNER JOIN alugueis ON corretores.id = alugueis.id_corretor
INNER JOIN imoveis ON imoveis.id = alugueis.id_imovel;

-- Consulta para mostrar todos os imóveis e os inquilinos que os alugaram, incluindo imóveis sem inquilino, usando LEFT JOIN
-- Objetivo: Esta consulta nos mostra todos os imóveis, incluindo os que ainda não foram alugados
SELECT imoveis.endereco AS imovel, inquilinos.nome AS inquilino
FROM imoveis
LEFT JOIN alugueis ON imoveis.id = alugueis.id_imovel
LEFT JOIN inquilinos ON alugueis.id_inquilino = inquilinos.id;

-- Consulta para mostrar o nome do proprietário, o endereço do imóvel e o nome do inquilino que alugou o imóvel
-- Objetivo: Esta consulta nos dá uma visão completa, mostrando os proprietários, os imóveis e os inquilinos associados
SELECT proprietarios.nome AS proprietario, imoveis.endereco AS imovel, inquilinos.nome AS inquilino
FROM proprietarios
INNER JOIN imoveis ON proprietarios.id = imoveis.id_proprietario
INNER JOIN alugueis ON imoveis.id = alugueis.id_imovel
INNER JOIN inquilinos ON alugueis.id_inquilino = inquilinos.id;
