#define MAX_SIM 20

void set_random(Vtop *dut, vluint64_t sim_unit) {
    dut->start_i = 1;
    dut->n_i = 12;
    dut->data_i = 5;
    dut-> rst_ni = 1;
}
