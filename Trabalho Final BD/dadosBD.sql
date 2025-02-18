USE imobiliaria;

-- Inserindo Proprietários
INSERT INTO proprietarios (nome, email, telefone) VALUES
('Carlos Silva', 'carlos@email.com', '11987654321'),
('Mariana Souza', 'mariana@email.com', '11976543210'),
('João Pereira', 'joao@email.com', '11965432109'),
('Ana Lima', 'ana@email.com', '11954321098'),
('Roberto Mendes', 'roberto@email.com', '11943210987'),
('Fernanda Costa', 'fernanda@email.com', '11932109876'),
('Gustavo Ribeiro', 'gustavo@email.com', '11921098765');

-- Inserindo Corretores
INSERT INTO corretores (nome, creci, email, telefone) VALUES
('Paulo Martins', '12345-SP', 'paulo@email.com', '11911111111'),
('Juliana Rocha', '23456-SP', 'juliana@email.com', '11922222222'),
('Fernando Lopes', '34567-SP', 'fernando@email.com', '11933333333'),
('Patricia Almeida', '45678-SP', 'patricia@email.com', '11944444444'),
('Ricardo Santos', '56789-SP', 'ricardo@email.com', '11955555555'),
('Amanda Figueiredo', '67890-SP', 'amanda@email.com', '11966666666'),
('Thiago Nunes', '78901-SP', 'thiago@email.com', '11977777777');

-- Inserindo Imóveis
INSERT INTO imoveis (endereco, tipo, valor, id_proprietario) VALUES
('Rua A, 123', 'Casa', 250000.00, 1),
('Rua B, 456', 'Apartamento', 180000.00, 2),
('Rua C, 789', 'Terreno', 75000.00, 3),
('Rua D, 101', 'Comercial', 300000.00, 4),
('Rua E, 202', 'Casa', 270000.00, 5),
('Rua F, 303', 'Apartamento', 220000.00, 6),
('Rua G, 404', 'Comercial', 500000.00, 7);

-- Inserindo Inquilinos
INSERT INTO inquilinos (nome, email, telefone) VALUES
('Lucas Amaral', 'lucas@email.com', '11988888888'),
('Beatriz Mendes', 'beatriz@email.com', '11999999999'),
('Eduardo Lima', 'eduardo@email.com', '11900000000'),
('Camila Ferreira', 'camila@email.com', '1188887777'),
('Rafael Duarte', 'rafael@email.com', '1177776666'),
('Sabrina Costa', 'sabrina@email.com', '1166665555'),
('Bruno Alves', 'bruno@email.com', '1155554444');

-- Inserindo Contatos entre Proprietários e Corretores
INSERT INTO contatos_proprietario_corretor (id_proprietario, id_corretor) VALUES
(1, 1), (1, 2), (2, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 7), (7, 1);

-- Inserindo Atendimentos entre Inquilinos e Corretores
INSERT INTO atendimentos_inquilino_corretor (id_inquilino, id_corretor) VALUES
(1, 1), (1, 3), (2, 2), (2, 4), (3, 5), (4, 6), (5, 7), (6, 1), (7, 2);

-- Inserindo Aluguéis
INSERT INTO alugueis (id_inquilino, id_imovel, data_inicio, data_fim, valor_aluguel) VALUES
(1, 1, '2024-01-01', '2025-01-01', 2500.00),
(2, 2, '2024-02-01', '2025-02-01', 1800.00),
(3, 3, '2024-03-01', NULL, 750.00),
(4, 4, '2024-04-01', '2025-04-01', 3000.00),
(5, 5, '2024-05-01', NULL, 2700.00),
(6, 6, '2024-06-01', '2025-06-01', 2200.00),
(7, 7, '2024-07-01', NULL, 5000.00);

