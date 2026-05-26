-- ============================================================================
-- SCRIPTS DE AUDITORIA, CONSULTAS SIMPLES E RELATÓRIOS GERENCIAIS AVANÇADOS
-- ============================================================================

-- ----------
-- CONSULTAS
-- ----------

-- Consultar toda a base cadastral de Clientes
SELECT * FROM cliente;

-- Consultar o catálogo de Produtos
SELECT * FROM produto;

-- Consultar os níveis e registros de movimentações no Estoque
SELECT * FROM estoque;

-- Consultar o fluxo de caixa e transações financeiras
SELECT * FROM pagamento;

-- Consultar parceiros e Fornecedores
SELECT * FROM fornecedor;


-- Relatório Comercial
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


-- Relatório de Faturamento por Cliente
SELECT 
    c.nome_cliente AS "Cliente TitanX",
    p.data_pedido AS "Data da Compra",
    pag.metodo_pagamento AS "Forma de Pagamento",
    pag.valor_total_pagamento AS "Valor Pago (R$)"
FROM pedido p
JOIN cliente c ON p.fk_id_cliente = c.id_cliente
JOIN pagamento pag ON pag.fk_id_pedido = p.id_pedido
ORDER BY pag.valor_total_pagamento DESC;


-- Indicador Financeiro Consolidado
SELECT SUM(valor_total_pagamento) AS "Faturamento Total TitanX (R$)" 
FROM pagamento;


-- Filtro Comercial de Segmentação
SELECT nome_cliente, cpf_cliente, email_cliente 
FROM cliente 
WHERE sexo_cliente = 'F';


-- Auditoria de Logística e Estoque
SELECT nome_produto_estoque, data_ultima_entrada, data_ultima_saida
FROM estoque
ORDER BY data_ultima_entrada DESC;
