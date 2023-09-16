module top (
    //inputs
    input logic clk_i,
    input logic rst_ni,
    input logic start_i,
    input logic [7:0] data_i, n_i,
    //outputs
    output logic done_o,
    output logic [7:0] sum_o
);
sum sum_module (
    .*
); 
endmodule
