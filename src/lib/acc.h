#pragma once

class acc
{
    public:
        void add(int i);
        void sub(int i);

        inline auto get() const
        {
            return m_acc;
        }

    private:
        int m_acc = 0;
};
