-- ============================================================================
-- SCRIPTS DE AUDITORIA, CONSULTAS SIMPLES E RELATÓRIOS GERENCIAIS AVANÇADOS
-- PROJETO DE EXTENSÃO: TITANX TECHNOLOGIES
-- ============================================================================

-- -----------------------
-- CONSULTAS ESTRUTURAIS
-- -----------------------

-- Consultar toda a base cadastral de Clientes
SELECT * FROM cliente;

-- Consultar o catálogo de Produtos
SELECT * FROM produto;

-- Consultar os níveis e registros de movimentações no Estoque
SELECT * FROM estoque;

-- Consultar o fluxo de transações financeiras
SELECT * FROM pagamento;

-- Consultar parceiros e Fornecedores
SELECT * FROM fornecedor;


-- ------------------------------
-- INTELIGÊNCIA DE DADOS & JOINs
-- ------------------------------

-- 1. Relatório Comercial Integrado
SELECT 
    c.nome_cliente AS "Cliente TitanX",
    p.data_pedido AS "Data da Solicitação",
    prod.nome_produto AS "Software/Solução Adquirida",
    pag.metodo_pagamento AS "Canal de Pagamento",
    pag.valor_total_pagamento AS "Faturamento Líquido (R$)"
FROM pedido p
JOIN cliente c ON p.fk_id_cliente = c.id_cliente
JOIN produto prod ON p.fk_id_produto = prod.id_produto
JOIN pagamento pag ON pag.fk_id_pedido = p.id_pedido
ORDER BY p.data_pedido ASC;


-- 2. Relatório de Faturamento por Cliente (Filtro por Maior Valor)
SELECT 
    c.nome_cliente AS "Cliente TitanX",
    p.data_pedido AS "Data da Compra",
    pag.metodo_pagamento AS "Forma de Pagamento",
    pag.valor_total_pagamento AS "Valor Pago (R$)"
FROM pedido p
JOIN cliente c ON p.fk_id_cliente = c.id_cliente
JOIN pagamento pag ON pag.fk_id_pedido = p.id_pedido
ORDER BY pag.valor_total_pagamento DESC;


-- 3. Indicador Financeiro Consolidado (Função de Agregação SUM)
SELECT SUM(valor_total_pagamento) AS "Faturamento Total TitanX (R$)" 
FROM pagamento;


-- 4. Filtro Comercial de Segmentação (Cláusula WHERE)
SELECT nome_cliente, cpf_cliente, email_cliente 
FROM cliente 
WHERE sexo_cliente = 'F';


-- 5. Auditoria de Logística e Estoque (Cláusula ORDER BY)
SELECT nome_produto_estoque, data_ultima_entrada, data_ultima_saida
FROM estoque
ORDER BY data_ultima_entrada DESC;
