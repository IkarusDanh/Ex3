module sum1 (
    //inputs
    input logic clk_i,
    input logic rst_ni,
    input logic start_i,
    input logic [7:0] data_i, n_i,
    //outputs
    output logic done_o,
    output logic [7:0] sum_o
);
//Wire
logic [7:0] get_sum =   0;
logic [7:0] counter =   0;
logic [7:0] get_n   =   0;
logic       states  =   0;
//Algorithm
always_ff @( posedge clk_i ) begin
    if (!rst_ni) begin 
        get_sum <=  0;
        get_n   <=  n_i;
        counter <=  0;
        done_o  <=  0;
    end
    else begin
        case (states)
            0: begin
                if (start_i && !done_o ) begin
                    states  <=  1;
                    get_n   <=  n_i;
                    get_sum <=  data_i;
                end
                else states <= 0;
            end
            1: begin
                if (counter < (get_n - 1)) begin
                    get_sum <=  (get_sum + data_i);
                    counter <=  (counter + 1);
                end
                else begin
                    sum_o   <=  get_sum;
                    done_o  <=  1;
                    counter <=  0;
                    states  <=  0;
                end
            end
        endcase
    end
end
endmodule
