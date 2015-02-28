#include "../include/commit.h"

Commit::Commit(int code) {
    sprintf(code_, CODE_FORMAT, code);
}


Refund::Refund(int code, string buyer_name, string seller_name, double credit) :
        Commit(code),
        buyer_name_(buyer_name),
        seller_name_(seller_name) {

    // Format attributes
    buyer_name_.resize(NAME_SIZE, BLANK);
    seller_name_.resize(NAME_SIZE, BLANK);
    if (credit == int(credit))
        sprintf(credit_, CREDIT_WO_DEC_FORMAT, (int) credit);
    else
        sprintf(credit_, CREDIT_W_DEC_FORMAT, credit);

    // Format the entire line - XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
    stringstream temp;
    temp << code_ << ' ' << buyer_name_ << ' ' << seller_name_ << ' ' << credit_;
    commit_ = temp.str();
}

string Refund::commit() {
    return commit_;
}


BuySell::BuySell(int code, string event_name, string seller_name, int num_tickets, double price) :
        Commit(code),
        event_name_(event_name),
        seller_name_(seller_name) {

    // format attributes to correct sizes
    event_name_.resize(EVENT_SIZE, BLANK);
    seller_name_.resize(NAME_SIZE, BLANK);
    sprintf(num_tickets_, NUMTIC_FORMAT, num_tickets);
    if (price == int(price))
        sprintf(price_, PRICE_WO_DEC_FORMAT, (int) price);
    else
        sprintf(price_, PRICE_W_DEC_FORMAT, price);

    // format the entire string - XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP
    stringstream temp;
    temp << code_ << ' ' << event_name_ << ' ' << seller_name_ << ' ' << num_tickets_ << ' ' << price_;
    commit_ = temp.str();
}

string BuySell::commit() {
    return commit_;
}


Regular::Regular(int code, string name, string type, double credit) :
        Commit(code),
        name_(name),
        type_(type) {

    // format attributes
    name_.resize(NAME_SIZE, BLANK);
    type_.resize(TYPE_SIZE, BLANK);
    if (credit == int(credit))
        sprintf(credit_, CREDIT_WO_DEC_FORMAT, (int) credit);
    else
        sprintf(credit_, CREDIT_W_DEC_FORMAT, credit);

    // format the entire string - XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    stringstream temp;
    temp << code_ << ' ' << name_ << ' ' << type_ << ' ' << credit_;
    commit_ = temp.str();
}

string Regular::commit() {
    return commit_;
}
